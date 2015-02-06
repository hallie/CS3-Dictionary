/* create a new instance of the Marionette app */
var app = new Backbone.Marionette.Application();
 
/* add the initial region which will contain the app */
app.addRegions({
    /* reference to container element in the HTML file */
    appRegion: '#AppBase'
});
 
/* define a module to keep the code modular */
app.module('App',function(module, App, Backbone, Marionette, $, _){
     
    /* definition for dictionary model, with default example of data structure */
    module.DictModel = Backbone.Model.extend({
        defaults: {
            word: 'Butts',
            def: 'Coo'
        }
    });
 
    /* definition for dictionary collection */
    module.DictCollection = Backbone.Collection.extend({
         
        /* set model type used for this collection */
        model: module.DictModel,
 
        /* comparator determines how collection is sorted */
        comparator: 'authorLast'
    });
 
    /* definition for individual item view */
    module.DictItemView = Marionette.ItemView.extend({
        tagName: 'li',
 
        /* set the template used to display this view */
        template: '#itemView-template',
 
        /* used to show the order in which these method are called */
        initialize: function(){ console.log('DictItemView: initialize >>> ' + this.model.get('word')) },
        onRender: function(){ console.log('DictItemView: onRender >>> ' + this.model.get('word')) },
        onShow: function(){ console.log('DictItemView: onShow >>> ' + this.model.get('word')) }
    });
 
    /* definition for collection view */
    module.DictCollectionView = Marionette.CollectionView.extend({
        tagName: 'ul',
 
        /* explicitly set the childview (formerly 'itemView') used to display the models in this collection */
        childView: module.DictItemView,
 
        initialize: function(){ console.log('DictCollectionView: initialize') },
        onRender: function(){ console.log('DictCollectionView: onRender') },
        onShow: function(){ console.log('DictCollectionView: onShow') }
    });
 
    /* define a view; in this case a 'LayoutView' (formerly 'Layout') */
    module.AppLayoutView = Marionette.LayoutView.extend({
         
        /* the auto-generated element which contains this view */
        tagName: 'div',
 
        /* id attribute for the auto-generated container element */
        id: 'AppContainer',
 
        /* reference to the template which will be rendered for this view */
        template: '#layout-template',
 
        /* define the regions within this layout, into which we will load additional views */
        regions: {
            'RegionOne' : '#regionOne'
        },
 
        /* called when the view initializes, before it displays */
        initialize: function() {
            console.log('main layout: initialize');
        },
 
        /* called when view renders in the DOM. This is a good place to 
            add nested views, because the views need existing DOM elements
            into which to be rendered. */
        onRender: function() {
            console.log('main layout: onRender');
             
            /* create an array of dictionaries using anonymouse objects;
                the objects have the same structure as in the 'defaults'
                attribute of the module.DictModel definition */
            var dictArray = [];
            dictArray.push({word:"Lomax", def:"Awesome"});
 
            /* create a collection using the array of anonymous objects */
            var dictCollection = new module.DictCollection(dictArray);
 
            /* create new instance of the collection view using the dictCollection */
            var dictCollectionView = new module.DictCollectionView({collection: dictCollection});
 
            /* display the collection view in region 1 */
            this.RegionOne.show(dictCollectionView);
        },
 
        /* called when the view displays in the UI */
        onShow: function() {
            console.log('main layout: onShow');
        }
    });
 
    /* Tell the module what to do when it is done loading */
    module.addInitializer(function(){
        /* create a new instance of the layout from the module */
        var layout = new module.AppLayoutView();
 
        /* display the layout in the region defined at the top of this file */
        app.appRegion.show(layout);
    });
});
 
/* once the DOM initializes, start the app */
$(document).ready(function() {app.start();});
