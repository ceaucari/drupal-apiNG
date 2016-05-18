# [apiNG](https://github.com/JohnnyTheTank/apiNG) implementation for Drupal 8

Only [Social Wall](http://aping.js.org/) implemented so far

[Sandbox page in drupal.org](https://www.drupal.org/sandbox/ceaucari/2712353)

### 1. Install

Install like any drupal module

Right now it uses libraries from CDN but the option to use local libraries will be available too.

##### Drush commands available to download libraries:

	drush aping-angular
	drush aping-aping

### 2. Enable the block
Place the "apiNG Social Wall" block in any region and see it in action with the default accounts.

### 3. Add your own accounts
 Specify your accounts details on social-wall.tpl.php

### 4. Create access tokens
Some accounts require tokens, and they need to be specified in aping/aping-config.js more details about it [here](https://aping.readme.io/docs/configuration)

### 5. Hide your keys
After adding your keys in aping-config.js remember to obfuscate the file with a tool like [this](https://javascriptobfuscator.com/Javascript-Obfuscator.aspx)


---

#### TO DO:
* Make paths relative to module instead of drupal root for images in aping-design-default.js
* Add configuration options to the block and auto generte the aping-config.js file obfuscated.
* Load bootstrap on non bootstrap themes
* create hook uninstall ?
