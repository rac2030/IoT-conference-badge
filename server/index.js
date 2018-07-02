require('now-env')
const express = require('express')
const net = require('net')
const fmt = require('./serialization')
const srv = require('./services')
const log = require('morgan')

const handleRequest = async function (request) {
  let requestType = (request['meta']['type'] || '').trim()
  let service = srv[requestType]
  if (!service) {
    throw new Error(`Unknown request type: ${requestType}`)
  }
  return service(request)
}

if (process.env.TCP_ENABLE === 'yes') {
  const TCP_DELIMITER = '\r'

  // Configure TCP interface
  net.createServer(function (socket) {
    let completeData = ''
    const name = `${socket.remoteAddress}:${socket.remotePort}`
    socket.name = name
    console.log(`Client connected: ${name}`)

    socket.on('close', () => console.log(`Closed client: ${name}`))
    socket.on('disconnect', () => console.log(`Disconnected client: ${name}`))
    socket.on('data', function (data) {
      try {
        completeData += data.toString()
        if (completeData.indexOf(TCP_DELIMITER) < 0) {
          return
        }

        console.log(`Received from client: ${name}, raw data: ${completeData}`)
        const request = fmt.deserialize(name, completeData)
        const response = handleRequest(request)
        socket.write(fmt.serialize(response) + TCP_DELIMITER)
      } catch (error) {
        console.error(`Failed to parse message from client: ${name}, raw data: ${completeData}`)
        console.error(error)
      }
    })
  }).listen(3000).on('listening', () => console.log('Started TCP Server on 3000'))
}

// Configure HTTP interface
const app = express()
app.use(express.json())
app.use(log('combined'))

app.post('/', async (request, res) => {
  const response = await handleRequest(request.body)
  res.send(response)
})
app.get('/', async (request, res) => {
  if (Object.keys(request.query).length > 0) {
    const response = await handleRequest({ meta: request.query })
    res.send(response)
  } else {
    res.sendFile(__dirname + '/index.html')
  }
})

app.listen(80, () => console.log('Started HTTP Server on 80'))