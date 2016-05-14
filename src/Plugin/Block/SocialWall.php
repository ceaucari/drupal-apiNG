<?php

namespace Drupal\aping\Plugin\Block;

use Drupal\Core\Block\BlockBase;

/**
 * Provides a 'aping' Social Wall block.
 *
 * @Block(
 *  id = "social_wall",
 *  admin_label = @Translation("Social Wall"),
 * )
 */
class SocialWall extends BlockBase {

  /**
   * {@inheritdoc}
   */
  public function build() {
    return array(
      '#theme' => 'social_wall',
      // '#module_path' => [drupal_get_path('module', 'aping')],
      '#variables' => ['name' => 'Social Wall'],
      '#attached' => array(
        'library' =>  array(
          // Angular
          'aping/aping.angularjs',

          // apiNG & plugins
          'aping/aping.aping',

          // apiNG design dependencies
          'aping/aping.dependancies',

          // aping Config.
          'aping/aping.socialwall'
        ),
      ),
    );
  }
}
