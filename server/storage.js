let inMemoryStorage = {
  'messages': {},
  'badges': {},
  'data': {}
}

const get = function (collection, query) {
  let table = inMemoryStorage[collection]
  return table[query['id']]
}

const set = function (collection, query, doc) {
  let table = inMemoryStorage[collection]
  table[query['id']] = doc
}

const insert = function (collection, query, doc) {
  let table = inMemoryStorage[collection]
  let item = table[query['id']]
  if (typeof item === 'undefined') {
    item = [doc]
  } else {
    item.push(doc)
  }
  table[query['id']] = item
}

module.exports = {
  get,
  set,
  insert
}
