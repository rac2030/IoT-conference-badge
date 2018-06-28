const AWS = require('aws-sdk')

const getDynamoClient = function () {
  return new AWS.DynamoDB.DocumentClient({
    region: process.env.AWS_REGION
  })
}

const get = async function (collection, query) {
  let documentClient = getDynamoClient()
  let queryParams = { TableName: collection, Key: query }
  return documentClient.get(queryParams).promise()
}

const put = async function (collection, query, doc) {
  let documentClient = getDynamoClient()
  let item = Object.assign(doc, query)
  let putParams = { TableName: collection, Item: item }
  return documentClient.put(putParams).promise()
}

module.exports = {
  get,
  put
}
