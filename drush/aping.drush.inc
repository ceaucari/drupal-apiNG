<?php


/**
 * @file
 * aping.drush.inc
 * @author César Castillo http://drupal.org/u/ceaucari
 * @copyright GNU GPL
 *
 * drush integration for apiNG.
 * 'drush aping-all' will install all the required libraries
 * 'drush aping-angular' will install all the required libraries
 */

//define('APING_ANGULAR_DOWNLOAD_URI', 'https://ajax.googleapis.com/ajax/libs/angularjs/1.5.0/angular.min.js');


/**
 * Implements hook_drush_command().
 *
 * In this hook, you specify which commands your
 * drush module makes available, what it does and
 * description.
 *
 * Notice how this structure closely resembles how
 * you define menu hooks.
 *
 * See `drush topic docs-commands` for a list of recognized keys.
 *
 * @return
 *   An associative array describing your command(s).
 */
function aping_drush_command() {
  $items = array();

  // the key in the $items array is the name of the command.
  $items['aping-angular'] = array(
    'callback' => 'drush_aping_angular_download',
    'description' => dt('Download and install AngularJS.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap.
    'arguments' => array(
      'path' => dt('Optional. A path where to install AngularJS. If omitted Drush will use the default location.'),
    ),
    'aliases' => array('apingangular'),
  );
  $items['aping-aping'] = array(
    'callback' => 'drush_aping_aping_download',
    'description' => dt('Download and install apiNG.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap.
    'arguments' => array(
      'path' => dt('Optional. A path where to install apiNG. If omitted Drush will use the default location.'),
    ),
    'aliases' => array('aping-self'),
  );

  return $items;
}

/**
 * Implements hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'
 *
 * @param
 *   A string with the help section (prepend with 'drush:')
 *
 * @return
 *   A string with the help text for your command.
 */
function aping_drush_help($section) {
  switch ($section) {
    case 'drush:aping-angular':
      return dt('Download and install AngularJS, default location is sites/all/libraries/angularjs.');
    case 'drush:aping-aping':
      return dt('Download and install apiNG, default location is sites/all/libraries/aping.');
  }
}

// TO DO: Loop through the libraries to install and keep it DRY

// function to download AngularJS
function drush_aping_angular_download() {
  if(module_exists('libraries')) {
    $path = 'sites/all/libraries/angularjs';

    // Create the path if it does not exist.
    if (!is_dir($path)) {
      drush_op('mkdir', $path);
      drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
    }
  }
  else {
    drush_log(dt('You need to install the libraries module first', array('@path' => $path)), 'error');
  }
  drush_op('chdir', $path);
  // Download the plugin.
  if (drush_shell_exec('wget https://ajax.googleapis.com/ajax/libs/angularjs/1.5.0/angular.min.js')) {
    drush_log(dt('angularjs has been downloaded to @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to download angularjs to @path', array('@path' => $path)), 'error');
  }
}


// function to download apiNG
function drush_aping_aping_download() {
  if(module_exists('libraries')) {
    $path = 'sites/all/libraries/aping';

    // Create the path if it does not exist.
    if (!is_dir($path)) {
      drush_op('mkdir', $path);
      drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
    }
  }
  else {
    drush_log(dt('You need to install the libraries module first', array('@path' => $path)), 'error');
  }
  drush_op('chdir', $path);
  // Download the plugin.
  if (drush_shell_exec('wget https://cdn.jsdelivr.net/aping/latest/aping.min.js')) {
    drush_log(dt('apiNG has been downloaded to @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to download apiNG to @path', array('@path' => $path)), 'error');
  }
}
