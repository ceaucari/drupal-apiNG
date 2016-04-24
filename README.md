# [apiNG](https://github.com/JohnnyTheTank/apiNG) implementation for Drupal

Only [Social Wall](http://aping.js.org/) implemented so far

[Sandbox page in drupal.org](https://www.drupal.org/sandbox/ceaucari/2712353)

### 1. Install

Install like any drupal module

Right now it uses libraries from CDN but the option to use local libraries will be available too.

##### Drush commands available to download libraries:

	drush aping-angular
	drush aping-aping

### 2. Add directive

We need to add a directive on html.tpl.php like this:

	<html data-ng-app="drupalApp" xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>
			<!-- REST OF THE FILE HERE -->
	</html>

Optional: If we want the directive to appear only on certain pages, add a preprocess function on the theme's template.php file like this: (replace MYTHEME)


	/**
	 * Use custon html.tpl.php files if they exist.
	 *
	 */
	function MYTHEME_preprocess_html (&$vars) {
	if (module_exists('path')) {
	    $alias = drupal_get_path_alias(str_replace('/edit','',$_GET['q']));
	    if ($alias != $_GET['q']) {
	      $template_filename = 'html';
	      foreach (explode('/', $alias) as $path_part) {
	        $template_filename = $template_filename . '__' . $path_part;
	        $vars['theme_hook_suggestions'][] = $template_filename;
	      }
	    }
	  }
	}


This way we can have a html--mypage.tpl.php
to be able to add the directive  only to the pages where the block will be displayed.

### 3. Add your accounts
 Specify your accounts details on social-wall.tpl.php

### 4. Create access tokens
Some accounts require tokens, and they need to be specified in aping/aping-config.js more details about it [here](https://aping.readme.io/docs/configuration)

### 5. Hide your keys
After adding your keys in aping-config.js remember to obfuscate the file with a tool like [this](https://javascriptobfuscator.com/Javascript-Obfuscator.aspx)

### 6. Enable the block
Place the "apiNG Social Wall" block in any region to make it visible.

---

#### TO DO:
* Only attach angular if it's not being loaded before to avoid conflicts.
* Add the angular directive to the html.tpl.php file with a preprocess function or using jquery.
* Add configuration options to the block and auto generte the aping-config.js file obfuscated.
* Load libraries from libraries folder
