<?php

/**
 * @file
 * Default template for feed displays that use the RSS style.
 *
 * @ingroup views_templates
 */
?>
<?php print "<?xml"; ?> version="1.0" encoding="utf-8" <?php print "?>\n"; ?>
<rss version="2.0"
  xml:base="<?php print $link; ?>"
  <?php print $namespaces; ?>>
  <channel>
    <title><?php print $title; ?></title>
    <description><?php print $description; ?></description>
    <language><?php print $langcode; ?></language>
    <?php print $channel_elements; ?>
    <!-- PubSubHubbub Discovery -->
    <link rel="hub" href="<?php print $hub_url; ?>" />
    <link rel="self" href="<?php print $feed_url; ?>" />
    <!-- End Of PubSubHubbub Discovery -->
    <?php print $items; ?>
  </channel>
</rss>
