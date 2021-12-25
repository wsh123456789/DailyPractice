const app = getApp()
const WXAPI = require('apifm-wxapi')
WXAPI.init('286148954c133f0ef2b691b47eeee57c')
const regeneratorRuntime=require('../../utils/runtime')
// pages/category/category.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    classData:[],
    curPage:1,
    goodsList:[],
    curIndex:0,
    categoryId:'',
    flag:true,
    isTab:false
  },

  getClassFy(){
    var that = this;
    WXAPI.goodsCategory().then(res=>{
      
      if(res.msg == "success"){
        that.setData({
          classData:res.data,
          categoryId:res.data[that.data.curIndex].id
        })
        that.getGoodsList();
      }
    })

    
  },

  getGoodsList(){
    var that = this;
    WXAPI.goods({
      categoryId:this.data.categoryId,
      page:this.data.curPage,
      pageSize: 10
    }).then(res=>{
      if(res.msg == "success"){
        that.setData({
          goodsList:[...that.data.goodsList,...res.data],
          flag:true
        })
      }
      else if(res.code==700 && this.isTab){
        that.setData({
          flag:false
        })
      }
    })

  },

  tab(event){
    var ind = event.currentTarget.dataset.ind;
    this.setData({
      curIndex:ind,
      categoryId:this.data.classData[ind].id,
      goodsList:[],
      curPage:1,
      
    })
    this.isTab=true;
    this.getGoodsList();
  },

  toBottom(){
    this.isTab=false;
    this.setData({
      curPage:this.data.curPage+1,
    })
    this.getGoodsList();
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    var index = options.index;
    if(index){
      this.setData({
        curIndex:index
      })
    }
    
    this.getClassFy();
    //this.getGoodsList();
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