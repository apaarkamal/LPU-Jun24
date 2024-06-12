const express = require('express')
const app = express();

app.use(express.json());

app.listen(3000, () => console.log('Listening on port 3000.'));

app.get('/hello', (req, res) => {
    console.log('Headers:', req.headers);
    console.log('Method:', req.method);
    res.send('Received GET request!\n');
});

app.post('/hello', (req, res) => {
    console.log('Headers:', req.headers);
    console.log('Method:', req.method);
    console.log('Body:', req.body);
    res.send('Received POST request!\n');
});