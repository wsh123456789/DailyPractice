// app.js
const WXAPI = require('apifm-wxapi')
WXAPI.init('286148954c133f0ef2b691b47eeee57c')

App({
  onLaunch() {
    // 展示本地存储能力
    const logs = wx.getStorageSync('logs') || []
    logs.unshift(Date.now())
    wx.setStorageSync('logs', logs)

    // 登录
    wx.login({
      success: res => {
        // 发送 res.code 到后台换取 openId, sessionKey, unionId
        var code = res.code;
        WXAPI.authorize({code}).then(function(res){
          var token = res.data.token;
          console.log(token)
          wx.setStorageSync('token', token)
        })

      }
    })
  },
  globalData: {
    userInfo: null
  }
})
