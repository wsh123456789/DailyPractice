// pages/categroy/index.js
const app = getApp()
const WXAPI = require('apifm-wxapi')
WXAPI.init('286148954c133f0ef2b691b47eeee57c')
const regeneratorRuntime=require('../../utils/runtime');

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

    },
    //获取左侧分类
    getClassFy(){
        var that=this;
        WXAPI.goodsCategory().then(res=>{
             console.log(res)
            if(res.code==0){
                that.setData({
                classData:res.data,
                categoryId:res.data[that.data.curIndex].id
            })
            that.getGoodsList();
            }
            
        })
    },
    //获取右侧分类
    getGoodsList(id){
        var that=this;
        if(id){

        }
        WXAPI.goods({
            categoryId: this.data.categoryId,
            page: this.data.curPage,
            pageSize: 10 
      }).then(res=>{
        //  console.log(res)
        if(res.code==0){
            that.setData({
                goodsList:[...this.data.goodsList,...res.data],
                flag:true,
            })
        }else if(res.code==700){
            that.setData({
                flag:false
            })
        }
      })
      
    },
    //切换商品
    tab(event){
        var ind=event.currentTarget.dataset.ind;
        var id=this.data.classData[ind].id
        this.setData({
            curIndex:ind,
            categoryId:id
        })
        //获取左侧类的id
        this.getGoodsList();
    },
    //当scroll-view滚动到底部执行
    toBottom(){
        console.log("id");
        this.setData({
            curPage:this.data.curPage+1,

        })
        this.getGoodsList();

    },
    /**
     * 生命周期函数--监听页面加载
     */
    onLoad: function (options) {
        this.getClassFy();
        // this.getGoodsList();
    },

})