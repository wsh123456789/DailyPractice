// pages/detail/detail.js
const WXAPI = require('apifm-wxapi')
WXAPI.init('e498a025374f91bf2771601c3ea6d797')
const regeneratorRuntime=require('../../utils/runtime')
Page({

  /**
   * 页面的初始数据
   */
  data: {
    detailNav:['商品简介','商品详情','商品评价'],
    curIndex:0,
    bannerData:[],
    goodsInfo:{},
    detailImgs:[],
    myt:0,
    myani:{},
    buyNumber:1
  },

  async getDetail(id){
    var res = await WXAPI.goodsDetail(id);
    var arr = [];
    if(res.msg == "success"){
      this.setData({
        bannerData:res.data.pics2,
        goodsInfo:res.data.basicInfo
      })
    }
    var content = res.data.content.split(' ')
    for(var i=0;i<content.length;i++){
      var s = content[i].split('=');
      if(s[0] && s[0] == "src"){
        arr.push(s[1].substring(1,s[1].length-1));
      }
    }

    this.setData({
      detailImgs:arr
    })
  },

  tab(event){
    var ind = event.currentTarget.dataset.ind;
    var that = this;
    const query = wx.createSelectorQuery()
    query.selectAll('.list').boundingClientRect()
    var t = 0
    query.exec(function(res){
      var res = res[0];
      t = res[ind].top-50;
      that.setData({
         myt:t
      })
    })
    this.setData({
      curIndex:ind,
    })
  },

  myScroll(event){
    var t = event.detail.scrollTop;
    var that = this;
    const query = wx.createSelectorQuery()
    query.selectAll('.list').boundingClientRect()
    query.exec(function(res){
      var res = res[0];
      for(var i=0;i<res.length;i++){
        if(t>res[i].top+410 && t<res[i].top+res[i].height+410){
          that.setData({
            curIndex:i
          })
        }
      }
    })
  },

  addCar(){
    this.ani=wx.createAnimation({

    })
    this.ani.translateY(0).step();
    this.setData({
      myani:this.ani.export()
    })
  },
  closeCar(){
    this.ani.translateY(250).step();
    this.setData({
      myani:this.ani.export()
    })
  },
  async realAddCar(){
    var token = wx.getStorageSync('token');
    var goodsId = this.data.goodsInfo.id;
    var res=await WXAPI.shippingCarInfoAddItem(token, goodsId, this.data.buyNumber, [], [])
    console.log(res)
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    var id  = options.id
    this.getDetail(id);
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