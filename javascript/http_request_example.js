const httpRequest = {
    host: 'localhost',
    port: 8080,
    method: 'POST',
    path: '/payments',
    headers: {
        'content-type': 'application/json',
        'content-length': 51,
    },
    body: '{"data": "This is a piece of data in JSON format."}'
}

const httpResponse = {
    statusCode: 200,
    headers: {
        'access-control-allow-origin': 'https://www.algoexpert.io',
        'content-type': 'application/json',
    },
    body: '{}'
}