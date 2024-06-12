const database = require('./caching_ws_database');
const express = require('express');
const app = express();

app.listen(3000, () => console.log('Listening on port 3000!'));

const accesses = {};

app.get('/index.html', function(req, res){
    const {user} = req.headers;
    
    if (user in accesses){
        const previousAccessTime = accesses[user];

        if(Date.now() - previousAccessTime < 5000){
            res.status(429).send('Too Many requests.\n');
            return;
        }
    }

    // Serve and store access time
    database.get('index.html', page => {
        accesses[user] = Date.now();
        res.send(page + '\n');
    });
});