const storage = require('./aws-storage')

const buildBadgeQuery = function (request) {
  return { badge_id: request['meta']['id'] }
}

const includeDatetimeKey = function (query) {
  return Object.assign(query, { datetime: new Date().toISOString() })
}

const receiveMessages = async function (request) {
  let query = buildBadgeQuery(request)
  let result = await storage.get('messages', query)
  let inbox = result ? result['Item'] : null
  if (!inbox) {
    inbox = { messages: [] }
  }

  let message = ''
  if (inbox['messages'] && inbox['messages'].length > 0) {
    message = inbox['messages'].shift()
  }
  await storage.put('messages', query, inbox)

  return {
    type: 'messages',
    payload: message
  }
}

const postMessages = async function (request) {
  let query = buildBadgeQuery(request)
  let result = await storage.get('messages', query)
  let inbox = result ? result['Item'] : null
  if (!inbox) {
    inbox = { messages: [] }
  }
  inbox['messages'].push(request['payload'])
  storage.put('messages', query, inbox)

  return {
    type: 'post-message',
    status: 'OK',
    payload: inbox['messages']
  }
}

const postData = async function (request) {
  let query = includeDatetimeKey(buildBadgeQuery(request))
  await storage.put('data', query, request['payload'])

  return {
    type: 'post-data',
    status: 'OK'
  }
}

const getBadgeName = async function (request) {
  let result = await storage.get('badges', buildBadgeQuery(request))
  let badgeName = result ? result['Item'] : ''

  return {
    type: 'get-badge-name',
    payload: badgeName
  }
}

const registerBadge = async function (request) {
  await storage.put('badges', buildBadgeQuery(request), request['payload'])

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
