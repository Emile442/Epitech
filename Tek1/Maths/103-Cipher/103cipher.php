<?php

require 'src/Cipher.php';

use src\cipher;

$cipher = new Cipher($argv[1], $argv[2], $argv[3]);

if (!$cipher->checkArgs())
    exit(84);

if (!$cipher->_getMode()) { // Encrypt
    $matrix = $cipher->getMatrix();
    $cipher->displayMatrix($matrix);
    $cipher->displayEncryptMsg($matrix);
} else { // Decrypt
    return (0);
}
