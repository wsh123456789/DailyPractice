#!/bin/bash
echo "build ..."
rm -rf ./wusihao.tar.gz

tar zcvf wusihao.tar.gz -C ./ static app.js package.json package-lock.json

echo "build success!"

#scp 包名 server(域名：端口：路径) to root@server (域名：端口：路径); => 回撤输入密码。
scp ./wusihao.tar.gz root@47.240.18.158:/var/www/wusihao

echo "send success!"



