// Read about the configuration file here: https://aping.readme.io/docs/configuration

"use strict";
angular.module('jtt_aping').config(['$provide', function ($provide) {
    $provide.value("apingDefaultSettings", {
        templateUrl : "sites/all/modules/planleft/modules/pl_social_wall/aping/social_template.html",
        items : "5", //items per request
        // maxItems: "<MAX_ITEMS_PER_APING>", //max items per aping instance
        orderBy : "timestamp", // order result list by property
        orderReverse : "true", //"true" or "false"
        model: "social", //e.g. "social", "event", "video", ...
        // getNativeData: false, // Use "true" for getting native data from plugins
        // removeDoubles: false, // Use "true" to remove identical objects from result array


        // apingApiKeys: {
        //     youtube : [{'apiKey': '<YOUR_YOUTUBE_API_KEY>'}],
        //     instagram: [{'access_token': '<YOUR_INSTAGRAM_TOKEN>'}],
        //     facebook: [{'access_token': '<YOUR_FACEBOOK_TOKEN>'}],
        //     twitter: [{'bearer_token': '<YOUR_TWITTER_BEARER_TOKEN>'}],
        //     vimeo: [{'access_token': '<YOUR_VIMEO_TOKEN>'}],
        //     tumblr: [{'api_key': '<YOUR_TUMBLR_API_KEY>'}],
        //     // ...
        }
    });
}]);
