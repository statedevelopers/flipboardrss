<?php

/**
 * @file
 * Default view template to display a item in an RSS feed.
 *
 * @ingroup views_templates
 */
?>
    <item>
      <title><?php print $title; ?></title>
      <link><?php print $link; ?></link>
      <description><![CDATA[<?php print $description; ?>]]></description>
      <content:encoded><![CDATA[<?php print $image . $content_encoded; ?>]]></content:encoded>
      <?php print $item_elements; ?>
    </item>
