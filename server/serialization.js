const deserialize = function (clientName, rawRayload) {
  if (!rawRayload) {
    throw new Error('Empty payload received')
  }

  // TODO: Temporary crap code until we define message format
  const clientId = rawRayload.substring(0, 16)
  const requestType = rawRayload.substring(16, 32)
  const data = rawRayload.substring(32)

  return {
    meta: {
      clientName: clientName,
      id: clientId,
      type: requestType
    },
    payload: data
  }
}

const serialize = function (data) {
  // TODO: Temporary crap code
  return data['payload']
}

module.exports = {
  deserialize,
  serialize
}
