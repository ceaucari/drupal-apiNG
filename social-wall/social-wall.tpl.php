<?php
/**
 * @file
 * AngularJS template to render a block.
 */

 /*
  * http://johnnythetank.github.io/youtube-channel-name-converter/
  * http://jelled.com/instagram/lookup-user-id#
  */
?>
<div data-ng-app="drupalApp">
  <div ng-controller="SocialWall">
    <div class="social-wall container-flouid">
        <aping
            template-url="sites/all/modules/aping/aping/social_template.html"
            items="3"
            model="social"
            order-by="timestamp"
            order-reverse="true"
            aping-youtube="[{'channelId':'UCG7bFLGTZ51oD2OfmQWp_2Q'}]"
            aping-instagram="[{'userId':'20724708', 'items':2}]"
            aping-facebook="[{'page':'BreakingBad'}]"
            aping-codebird="[{'user':'adidas', 'showAvatar':false}]"
            aping-flickr="[{'tags':'münchen'}]"
            aping-dailymotion="[{'userId':'electropose'}]"
            aping-tumblr="[{'page':'davidhinga'}]"
            aping-rss="[{'path':'http://blog.hackerearth.com/feed'}]"
            aping-vimeo="[{'channel':'worldhd'}]">
        </aping>
    </div>
  </div>
</div>
