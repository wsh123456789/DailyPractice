// pages/detail/index.js
const app = getApp()
const WXAPI = require('apifm-wxapi')
WXAPI.init('286148954c133f0ef2b691b47eeee57c')
const regeneratorRuntime=require('../../utils/runtime');
Page({

    /**
     * 页面的初始数据
     */
    data: {
        detailNav:['商品简介','商品详情','商品评价'],
        curIndex:0,
        bannerData:[],
        goodsInfo:[]
    },
    tab(event){
        var index=event.currentTarget.dataset.index;
        this.setData({
            curIndex:index,
        })
    },
    /**
     * 生命周期函数--监听页面加载
     */
    // 1027811
    async getDetail(id){
       var res=await WXAPI.goodsDetail(id)
       console.log(res)
       if(res.code==0){
           this.setData({
               bannerData:res.data.pics2,
               goodsInfo:res.data.basicInfo
           })
           console.log(res.data.content)
       }
    },
    onLoad: function (options) {
        console.log(options)
       var id=options.id
        this.getDetail(id)
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