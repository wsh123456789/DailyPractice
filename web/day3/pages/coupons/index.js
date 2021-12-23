// pages/coupons/index.js
const app = getApp()
const WXAPI = require('apifm-wxapi')
WXAPI.init('286148954c133f0ef2b691b47eeee57c')
const regeneratorRuntime=require('../../utils/runtime');
Page({

    /**
     * 页面的初始数据
     */
    data: {
      couponsNav:['可领','已领','失效','口令'],
      curIndex:0,
      couponsList:[]
    },
  
    async getCoupons(){
      var res = await WXAPI.coupons();
      console.log(res)
      this.setData({
        couponsList:res.data
      })
    },
  
    tab(event){
      var ind = event.currentTarget.dataset.ind;
      this.setData({
        curIndex:ind,
      })
    },
  
    /**
     * 生命周期函数--监听页面加载
     */
    onLoad: function (options) {
      this.getCoupons();
    },
  
    /**
     * 生命周期函数--监听页面初次渲染完成
     */
    onReady: function () {
  
    },
  
    /**
     * 生命周期函数--监听页面显示
     */
    onShow: function () {
  
    },
  
    /**
     * 生命周期函数--监听页面隐藏
     */
    onHide: function () {
  
    },
  
    /**
     * 生命周期函数--监听页面卸载
     */
    onUnload: function () {
  
    },
  
    /**
     * 页面相关事件处理函数--监听用户下拉动作
     */
    onPullDownRefresh: function () {
  
    },
  
    /**
     * 页面上拉触底事件的处理函数
     */
    onReachBottom: function () {
  
    },
  
    /**
     * 用户点击右上角分享
     */
    onShareAppMessage: function () {
  
    }
  })