<?php

/**
 * Implements hook_rules_action_info().
 */
function replicate_rules_action_info() {
  return array(
    'replicate_entity' => array(
      'label' => t('Replicate an Entity (Improved)'),
      'group' => t('Replicate'),
      'parameter' => array(
        'data' => array(
          'type' => 'entity',
          'label' => t('Entity'),
          'description' => t('Specifies the entity, which should be saved permanently.'),
          'restriction' => 'selector',
          'wrapped' => TRUE,
        ),
      ),
      'provides' => array(
        'replica_entity' => array(
          'type' => 'entity',
          'label' => t('Replica entity'),
          'wrapped' => TRUE,
        ),
      ),
      'base' => 'replicate_rules_replicate_entity'
    ),
  );
}

/**
 * Action: Clone entity.
 */
function replicate_rules_replicate_entity($wrapper) {
  $info = $wrapper->info();
  $cloned_entity = replicate_clone_entity($info['type'], $wrapper->value());
  return array('replica_entity' => entity_metadata_wrapper($info['type'], $cloned_entity));
}
