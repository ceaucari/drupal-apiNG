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

define('APING_ANGULAR_DOWNLOAD_URI', 'https://ajax.googleapis.com/ajax/libs/angularjs/1.5.0/angular.min.js');


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
    'callback' => 'drush_aping_angular',
    'description' => dt('Download and install AngularJS.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap.
    'arguments' => array(
      'path' => dt('Optional. A path where to install AngularJS. If omitted Drush will use the default location.'),
    ),
    'aliases' => array('apingangular'),
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
      return dt('Download and install AngularJS, default location is sites/all/libraries.');

  }
}

/**
 * Command to download AngularJS.
 */
function drush_aping_angular() {
  $args = func_get_args();
  if (!empty($args[0])) {
    $path = $args[0];
  }
  else {
    $path = 'sites/all/libraries';
  }

  // Create the path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  // Set the directory to the download location.
  $olddir = getcwd();
  chdir($path);

  $zip = APING_ANGULAR_DOWNLOAD_URI;
  $dirname = 'angularjs';

  // angularjs directory exists, bailing out
  if (is_dir($dirname)) {
    drush_log(dt('An existing AngularJS was found in @path, not continuing.', array('@path' => $path)), 'notice');
    return;
  }

  // Download the zip archive
  if ($filepath = drush_download_file($zip)) {
    $filename = basename($filepath);

    // Decompress the zip archive
    drush_tarball_extract($filename);
  }

  if (is_dir($dirname)) {
    drush_log(dt('AngularJS has been installed in @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to install AngularJS to @path', array('@path' => $path)), 'error');
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);
}
