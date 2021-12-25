// index.js
// 获取应用实例
const app = getApp()
const WXAPI = require('apifm-wxapi')
WXAPI.init('286148954c133f0ef2b691b47eeee57c')
const regeneratorRuntime=require('../../utils/runtime')
Page({
  data: {
   bannersData:[],
   categoryData:[],
   ZhiBoImg:'',
   miaoshaData:[],
   recommendStatusData:[],
   kanJiaData:[],
   pinTuanData:[],
   clock:'',
   curPage:1,
   goodsList:[],
   flag:false
  },
  
  goCategory(event){
    var index = event.currentTarget.dataset.index;
    wx.reLaunch({
      url: '../../pages/category/category?index='+index,
    })
  },

  async getBanner(){
    var res = await WXAPI.banners({type:'index'});
    if(res.msg == 'success'){
      this.setData({
        bannersData:res.data
      })
    }
  },

  async getCategory(){
    var res = await WXAPI.goodsCategory();
    if(res.msg == "success"){
      this.setData({
        categoryData:res.data
      })
    }
  },

  async getZhiBo(){
    var res = await WXAPI.adPosition('index-live-pic');
    if(res.msg == "success"){
      this.setData({
        ZhiBoImg:res.data.val
      })
    }
  },

  async getMiaoSha(){
    var res = await WXAPI.goods({
      miaosha: true
    })
    if(res.msg == "success"){
      this.setData({
        miaoshaData:res.data
      })
    }
  },

  async getRecommendStatus(){
    var res = await WXAPI.goods({
      recommendStatus: 1
    })
    if(res.msg == "success"){
      this.setData({
        recommendStatusData:res.data
      })
    }
  },

  async getKanJia(){
    var res = await WXAPI.goods({
      kanjia: true
    });
    if(res.msg == "success"){
      this.setData({
        kanJiaData:res.data
      })
    }
  },

  async getPinTuan(){
    var res = await WXAPI.goods({
      pingtuan: true
    });
    if(res.msg == "success"){
      this.setData({
        pinTuanData:res.data
      })
    }
  },

  getAllGoods(){
    wx.showToast({
      title: '加载中',
      icon: 'loading'
    })
    var that = this
    WXAPI.goods({
      categoryId: 0,
      page: this.data.curPage,
      pageSize: 10
    }).then(res=>{
      wx.hideToast({
          success: (res) => {},
        })
      if(res.msg=="success"){
        that.setData({
          goodsList:[...this.data.goodsList,...res.data]
        })
      }
      else{
        this.setData({
          flag:true
        })
      }
      
    })

  },

  goDetail(event){
    var id = event.currentTarget.dataset.id
    wx.redirectTo({
      url: '../../pages/detail/detail?id='+id,
    })
  },

  onLoad() {
    this.getBanner();
    this.getCategory();
    this.getZhiBo();
    this.getMiaoSha();
    this.getRecommendStatus();
    this.getKanJia();
    this.getPinTuan();
    this.getAllGoods();
    var that=this;
    this.data.intervarID= setInterval(function () {
      var leftTime = (new Date(2022, 1-1, 23, 17, 40, 0)) - (new Date()); //计算剩余的毫秒数
      var days = parseInt(leftTime / 1000 / 60 / 60 / 24, 10); //计算剩余的天数
      var hours = parseInt(leftTime / 1000 / 60 / 60 % 24, 10); //计算剩余的小时
      var minutes = parseInt(leftTime / 1000 / 60 % 60, 10);//计算剩余的分钟
      var seconds = parseInt(leftTime / 1000 % 60, 10);//计算剩余的秒数
      /*days = checkTime(days);
      hours = checkTime(hours);
      minutes = checkTime(minutes);
      seconds = checkTime(seconds);*/
      that.setData({
        clock: days + "天" + hours + "小时" + minutes + "分" + seconds + "秒"
      })
      if (days == '00' && hours == '00' && minutes == '00' && seconds=='00')
      {
        clearInterval(that.data.intervarID);
      }
    }, 1000
    )
  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {
    this.setData({
      curPage:this.data.curPage+1
    })
    this.getAllGoods();
  }
})
