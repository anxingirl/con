<?php

/**
 * @file
 * User page callbacks for the search module.
 */
function searchtabs_guancang_redirect($module) {

 // dpm(isset($_REQUEST['find_code']) && isset($_REQUEST['request']));
  $info = FALSE;
  switch ($module) {
    case 'guancang':
  // Also try to pull search keywords out of the $_REQUEST variable to
  // support old GET format of searches for existing links.
  //dpm(isset($_REQEUST['find_code']));
  if(isset($_REQUEST['find_code']) && isset($_REQUEST['request'])){
    $request = trim($_REQUEST['request']);
    $find_code = trim($_REQUEST['find_code']);
  } else {
    $request = '';
    $find_code = '';
  }
  //dpm('Location:http://opac.lib.bnu.edu.cn:8080/F?func=find-m&find_code='.$find_code.'&request='.$request);
  $path = 'http://opac.lib.bnu.edu.cn:8080/F?func=find-m&find_code='.$find_code.'&request='.$request;
    $options = array(
      'external' => TRUE,
  );
  drupal_goto($path, $options);
    break;
    
    case 'metalib':
  if(isset($_REQUEST['F_WRD'])){
    $f_wrd = trim($_REQUEST['F_WRD']);
  } else {
    $f_wrd = '';
  }
 //dpm('Location:http://search.lib.bnu.edu.cn:8080/V?FUNC=FIND-DB-1-LOCATE&MODE=locate&SUBMIT=search&pds_handle=GUEST&F-WRD='.$form_state['values']['F-WRD']);
  $path = 'http://search.lib.bnu.edu.cn:8080/V?FUNC=FIND-DB-1-LOCATE&MODE=locate&SUBMIT=search&pds_handle=GUEST&F-WRD='.$f_wrd;
  $options = array(
      'external' => TRUE,
  );
  //dpm($path);
  drupal_goto($path, $options);
  break;  
  
  case 'sfx':
  if(isset($_REQUEST['param_pattern_value'])){
    $param_pattern_value = trim($_REQUEST['param_pattern_value']);
  } else {
    $param_pattern_value = '';
  }
  $path = 'http://search.lib.bnu.edu.cn:9003/sfx_bnu/az/default?param_perform_value=searchTitle&param_pattern_value='.$param_pattern_value;
  //dpm('Location:http://search.lib.bnu.edu.cn:8080/V?FUNC=FIND-DB-1-LOCATE&MODE=locate&SUBMIT=search&pds_handle=GUEST&F-WRD='.$form_state['values']['F-WRD']);
  //$path = 'http://search.lib.bnu.edu.cn:8080/V?FUNC=FIND-DB-1-LOCATE&MODE=locate&SUBMIT=search&pds_handle=GUEST&F-WRD='.$f_wrd;
  $options = array(
      'external' => TRUE,
  );
  //dpm($path);
  drupal_goto($path, $options);
  break;  
  
  case 'baidu':
  if(isset($_REQUEST['wd'])){
    $wd = trim($_REQUEST['wd']);
  } else {
    $wd = '';
  }
  $path = 'http://xueshu.baidu.com/s?wd='.$wd;
 //dpm('Location:http://search.lib.bnu.edu.cn:8080/V?FUNC=FIND-DB-1-LOCATE&MODE=locate&SUBMIT=search&pds_handle=GUEST&F-WRD='.$form_state['values']['F-WRD']);
  //$path = 'http://search.lib.bnu.edu.cn:8080/V?FUNC=FIND-DB-1-LOCATE&MODE=locate&SUBMIT=search&pds_handle=GUEST&F-WRD='.$f_wrd;
  $options = array(
      'external' => TRUE,
  );
  //dpm($path);
  drupal_goto($path, $options);
  break;
  
  default:
  return array(
  'first_para' => array(
    '#type' => 'markup',
    '#markup' => 'A first paragraph',
  ),
  'second_para' => array(
    array('first item', 'second item', 'third item'),
    '#theme' => 'item_list',
  ),
);       
  break;
  }
}

/**
 * Menu callback; presents the search form and/or search results.
 *
 * @param $module
 *   Search module to use for the search.
 * @param $keys
 *   Keywords to use for the search.
 */
function searchtabs_view($module = NULL, $keys = '') {
  $info = FALSE;
  $keys = trim($keys);
  // Also try to pull search keywords out of the $_REQUEST variable to
  // support old GET format of searches for existing links.
  if (!$keys && !empty($_REQUEST['keys'])) {
    $keys = trim($_REQUEST['keys']);
  }

    // Redirect from bare /search or an invalid path to the default search path.
    $path = 'http://cn.bing.com?q=';
    if ($keys) {
      $path .= $keys;
    }
    //header('Location:'.$path);
}
