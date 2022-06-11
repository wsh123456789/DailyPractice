const express = require("express");

const server = express();

server.use('', express.static('./static'));

server.listen(8080, function () { //在8080端口启动
    console.log('Example app listening on port 8080');
})


