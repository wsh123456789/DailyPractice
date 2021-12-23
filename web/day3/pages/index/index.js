// index.js
// 获取应用实例
const app = getApp()
const WXAPI = require('apifm-wxapi')
WXAPI.init('286148954c133f0ef2b691b47eeee57c')
const regeneratorRuntime=require('../../utils/runtime');

Page({
  data: {
    bannersData:[],
    cateGroyData:[],
    zhiboImg:"",
    miaoshaData:[],
    baopinData:[],
    kanjiaData:[],
    pintuanData:[],
    curPage:1,
    goodsList:[],
    flag:false

  },
  //详情页
  goDetail(event){
    var id=event.currentTarget.dataset.id
    wx.redirectTo({
       url: '../detail/index?id='+id,
    })
  }, 
  async getBanner(){
    var res=await WXAPI.banners({type:"index"})
    //console.log(res)
    if(res.code==0){
      this.setData({
        bannersData:res.data
      })
    }
  },
  async getCateGroy(){
    var res=await WXAPI.goodsCategory()
    //console.log(res)
    if(res.code==0){
      this.setData({
        cateGroyData:res.data
      })
    }
  },
  async getZhibo(){
    var res=await WXAPI.adPosition( 'index-live-pic');
    //console.log(res)
     if(res.code==0){
       console.log(res)
       this.setData({
         zhiboImg:res.data.val
       })
     }
  },
  async getMiaoSha(){
    var res=await WXAPI.goods({
      miaosha:true
    })
    console.log(res)
    if(res.code==0){
      this.setData({
        miaoshaData:res.data
      })
    }
  },
  async getBaoPin(){
    var res=await WXAPI.goods({
      recommendStatus: 1
    })
  //  console.log(res)
   if(res.code==0){
      this.setData({
        baopinData:res.data
      })
   }
  },
  async getKanJia(){
    var res=await WXAPI.goods({
      kanjia: true
    });

    // console.log(res)
   if(res.code==0){
      this.setData({
        kanjiaData:res.data
      })
   }
  },
  async getPinTuan(){
    var res=await WXAPI.goods({
      pingtuan: true
    })

    // console.log(res)
   if(res.code==0){
      this.setData({
        pintuanData:res.data
      })
   }
  },
 getAllGoods(){
   wx.showToast({
     title: '加载中',
     icon:"loading"
   })
    var that=this;
    WXAPI.goods({
      categoryId: 0,
      page: this.data.curPage,
      pageSize: 10
    }).then(res=>{
      // console.log(res)
      wx.hideToast({
        success: (res) => {},
      })
      if(res.code==0){
        that.setData({
        goodsList:[...this.data.goodsList,...res.data]
      })
      }
      if(res.code==700){
        that.setData({
          flag:true
        })
      }
    
    })

  },
  onLoad() {
    this.getBanner();
    this.getCateGroy();
    this.getZhibo();
    this.getMiaoSha();
    this.getBaoPin();
    this.getKanJia();
    this.getPinTuan();
    this.getAllGoods()
  },
   /**
     * 页面上拉触底事件的处理函数
     */
    onReachBottom: function () {
        this.setData({
          curPage:this.data.curPage+1
        })
        this.getAllGoods()
    },
})
