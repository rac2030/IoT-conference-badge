const storage = require('./storage')

const receiveMessages = function (request) {
  let messages = storage.get('messages', { id: request['meta']['id'] })
  let message = ''
  if (messages && messages.length > 0) {
    message = messages.shift()
  }
  storage.set('messages', { id: request['meta']['id'] }, messages)

  return {
    type: 'messages',
    payload: message
  }
}

const postMessages = function (request) {
  let id = request['meta']['id']
  storage.insert('messages', { id: id }, request['payload'])
  let messages = storage.get('messages', { id: id })

  return {
    type: 'post-message',
    status: 'OK',
    payload: messages
  }
}

const postData = function (request) {
  let id = request['meta']['id']
  storage.insert('data', { id: id }, request['payload'])

  return {
    type: 'post-data',
    status: 'OK'
  }
}

const getBadgeName = function (request) {
  let badgeName = storage.get('badges', { id: request['meta']['id'] })

  return {
    type: 'get-badge-name',
    payload: badgeName
  }
}

const registerBadge = function (request) {
  storage.set('badges', { id: request['meta']['id'] }, request['payload'])

  return {
    type: 'register',
    status: 'OK'
  }
}

module.exports = {
  'receive-messages': receiveMessages,
  'post-messages': postMessages,
  'register-badge': registerBadge,
  'get-badge-name': getBadgeName,
  'post-data': postData
}
