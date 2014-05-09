<?php

/**
 * @file
 * Views plugins, handlers and hooks definition for Flipboard RSS module.
 */

/**
 * Implements hook_views_plugins().
 * Adds view types to views UI interface.
 */
function flipboardrss_views_plugins() {
  $plugins = array(
    'style' => array(
      'flipboardrss' => array(
        'title' => t('RSS Feed for Flipboard'),
        'help' => t('Generates an RSS feed compatible to Flipboard'),
        'handler' => 'flipboardrss_plugin_style_rss',
        'path' => FLIPBOARDRSS_PATH . '/views',
        'theme' => 'flipboardrss_view_rss',
        'theme file' => 'theme.inc',
        'theme path' => FLIPBOARDRSS_PATH . '/theme',
        'uses row plugin' => TRUE,
//        'uses fields' => TRUE,
        'uses options' => TRUE,
//        'uses grouping' => FALSE,
        'type' => 'feed',
      ),
      'flipboardrss_rows' => array(
        'title' => t('RSS Feed for rows in Flipboard'),
        'help' => t('Generates an RSS item for a single node, compatible to Flipboard'),
        'handler' => 'flipboardrss_plugin_row_style_rss',
        'path' => FLIPBOARDRSS_PATH . '/views',
        'theme' => 'flipboardrss_row_view_rss',
        'theme file' => 'theme.inc',
        'theme path' => FLIPBOARDRSS_PATH . '/theme',
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
//        'uses grouping' => FALSE,
        'type' => 'feed',
      ),
    ),
  );

  return $plugins;
}

/**
 * Implements hook_views_data().
 */
function flipboardrss_views_data(&$data) {
  $data['term_node']['term_multiple'] = array(
//    'group' => t('Taxonomy'),
    'title' => t('Body Content'),
    'help'=>; t('Node body field as the content of the story.'),
    'real field' => 'tid',
    'filter' => array(
      'handler' => 'flipboardrss_plugin_row_style_rss',
//      'hierarchy table' => 'term_hierarchy',
//      'numeric' => TRUE,
//      'skip base' => 'term_data',
//      'allow empty' => TRUE,
    ),
  );
}




/**
 * Implements hook_views_handlers().
 */
/*
function flipboardrss_views_handlers() {
  return array(
    'info' => array(
      'path' => FLIPBOARDRSS_PATH . '/views',
    ),
    'handlers' => array(
      'flipboardrss_handler_field_user_mail' => array(
        'parent' => 'views_handler_field_user_mail',
      ),
      'flipboardrss_handler_field_term_node_tid' => array(
        'parent' => 'views_handler_field_term_node_tid',
      ),
    ),
  );
}
*/













/**
 * Implements hook_views_data_alter().
 */
/*
function flipboardrss_views_data_alter(&$data) {
  $data['users']['mail']['field']['handler'] = 'flipboardrss_handler_field_user_mail';
  $data['node']['term_node_tid']['field']['handler'] = 'flipboardrss_handler_field_term_node_tid';
}
*/