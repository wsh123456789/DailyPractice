// pages/shop-cart/shop-cart.js
const WXAPI = require('apifm-wxapi')
WXAPI.init('e498a025374f91bf2771601c3ea6d797')
const regeneratorRuntime=require('../../utils/runtime')
Page({

  /**
   * 页面的初始数据
   */
  data: {
    hasGoods:true,
    carGoods:[],
    selectedArr:[],
    allPrice:0
  },

  async getCarGoods(){
    var token = wx.getStorageSync('token');
    var res = await WXAPI.shippingCarInfo(token);
    var seArr = this.data.selectedArr;
    if(res.code == 0){
      if(seArr.length == 0){
        var arr = new Array(res.data.items.length);
        arr.fill(true);
        this.setData({
          selectedArr:[...arr]
        })
      }
      this.setData({
        hasGoods:true,
        carGoods:res.data.items,
        
      })
      console.log(res);
      this.getSelectAllPrice();
    }else if(res.code == 700){
      this.setData({
        hasGoods:false
      })
    }
  },

  getSelectAllPrice(){
    var allP = 0;
    var goods = this.data.carGoods;
    var seArr = this.data.selectedArr;
    for(var i=0;i<goods.length;i++){
      if(seArr[i]){
        allP += goods[i].price*goods[i].number 
      } 
    }
    this.setData({
      allPrice:allP
    })
  },

  tabSwitch(event){
    var v = event.detail.value;
    var index = event.currentTarget.dataset.index;
    var arr = this.data.selectedArr;
    arr[index] = v;
    this.setData({
      selectedArr:[...arr]
    })
    this.getSelectAllPrice();
  },

  async addCount(event){
    var token = wx.getStorageSync('token');
    var goods = this.data.carGoods;
    var index = event.currentTarget.dataset.index;
    var key = goods[index].key;
    var number = goods[index].number+1;
    var res = await WXAPI.shippingCarInfoModifyNumber(token, key, number);
    this.getCarGoods();
    this.getSelectAllPrice();
  },

  async minusCount(event){
    var token = wx.getStorageSync('token');
    var goods = this.data.carGoods;
    var index = event.currentTarget.dataset.index;
    var key = goods[index].key;
    var number = goods[index].number-1;
    var res = await WXAPI.shippingCarInfoModifyNumber(token, key, number);
    if(number == 0){
      var res = await WXAPI.shippingCarInfoRemoveItem(token, key)
    }

    console.log(res);
    this.getCarGoods();
    this.getSelectAllPrice();
  },

  goIndex(){
    wx.switchTab({
      url: '../../pages/index/index'
    })
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {

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
    this.getCarGoods();
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