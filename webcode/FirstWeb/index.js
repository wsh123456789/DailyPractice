
//引入express模块
const express = require('express');
//创建express实例
const app = express();
//定义端口号
const port = 3000;
//添加路由
app.get('/', (req, res) => res.send('Hello World!'));
//绑定端口号
app.listen(port, () => console.log(`Example app listening on port ${port}!`));
