<?php

/**
 * @file
 * Preprocessors and helper functions to make theming easier.
 */

/**
 * Preprocess an RSS feed
 */

function template_preprocess_flipboardrss_view_rss(&$vars) {
  global $base_url;
  global $language;

  $view     = &$vars['view'];
  $options  = &$vars['options'];
  $items    = &$vars['rows'];

  $style    = &$view->style_plugin;

  // The RSS 2.0 "spec" doesn't indicate HTML can be used in the description.
  // We strip all HTML tags, but need to prevent double encoding from properly
  // escaped source data (such as &amp becoming &amp;amp;).
  $vars['description'] = check_plain(strip_tags($style->get_description()));

  if ($view->display_handler->get_option('sitename_title')) {
    $title = variable_get('site_name', 'Drupal');
    if ($slogan = variable_get('site_slogan', '')) {
      $title .= ' - ' . $slogan;
    }
  }
  else {
    $title = $view->get_title();
  }
  $vars['title'] = check_plain($title);

  // Figure out which display which has a path we're using for this feed. If there isn't
  // one, use the global $base_url
  $link_display_id = $view->display_handler->get_link_display();
  if ($link_display_id && !empty($view->display[$link_display_id])) {
    $path = $view->display[$link_display_id]->handler->get_path();
  }

  if ($path) {
    $path = $view->get_url(NULL, $path);
    $url_options = array('absolute' => TRUE);
    if (!empty($view->exposed_raw_input)) {
      $url_options['query'] = $view->exposed_raw_input;
    }

    // Compare the link to the default home page; if it's the default home page, just use $base_url.
    if ($path == variable_get('site_frontpage', 'node')) {
      $path = '';
    }

    $vars['link'] = check_url(url($path, $url_options));
  }

  $vars['langcode'] = check_plain($language->language);
  $vars['namespaces'] = drupal_attributes($style->namespaces);
  $vars['items'] = $items;
  $vars['channel_elements'] = format_xml_elements($style->channel_elements);

  // During live preview we don't want to output the header since the contents
  // of the feed are being displayed inside a normal HTML page.
  if (empty($vars['view']->live_preview)) {
    drupal_add_http_header('Content-Type', 'application/rss+xml; charset=utf-8');
  }
}

/**
 * Default theme function for all RSS rows.
 */
function template_preprocess_flipboardrss_view_row_rss(&$vars) {
  $item     = &$vars['row'];
  $vars['title'] = check_plain($item->title);
  $vars['link'] = check_url($item->link);
//  $vars['description'] = check_plain($item->description);
  $vars['description'] = $item->description;
  $vars['content_encoded'] = $item->content_encoded;
  $vars['image'] = '<figure>' . $item->image . '</figure>';
  $vars['item_elements'] = empty($item->elements) ? '' : format_xml_elements($item->elements);
}
