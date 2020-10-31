<?php

namespace src;

class Cipher
{
    private $msg;
    private $key;
    private $mode;

    public function __construct($msg, $key, $mode)
    {
        $this->msg = $msg;
        $this->key = $key;
        $this->mode = $mode;
    }

    public function _getMode()
    {
        return $this->mode;
    }

    public function _getMsg()
    {
        return $this->msg;
    }

    public function _getKey()
    {
        return $this->key;
    }

    public function checkArgs()
    {
        if (strlen($this->_getKey()) > 16)
            return (false);
        return (true);
    }

    private function _getMatrixSize($key_len)
    {
        if ($key_len == 1)
            return (1);
        else if ($key_len > 1 && $key_len <= 4)
            return (4);
        else if ($key_len > 4 && $key_len <= 9)
            return (9);
        else if ($key_len > 9 && $key_len <= 16)
            return (12);
        return (0);
    }

    public function getMatrix()
    {
        $key_len = strlen($this->_getKey());
        $key_array = str_split($this->_getKey());
        $matrix = array();

        for ($i = 0; $i < $key_len; $i++)
            $matrix[$i] = ord($key_array[$i]);
        for (; $key_len < $this->_getMatrixSize($key_len); $key_len++)
            $matrix[$key_len] = 0;

        return ($matrix);
    }

    public function displayMatrix($matrix)
    {
        $size = count($matrix);
        $sqr = sqrt($size);

        echo "Key matrix:\n";
        for ($i = 0; $i < $size; $i += $sqr) {
            for ($j = 0; $j < $sqr; $j++)
                echo "{$matrix[$i + $j]}\t";
            echo "\n";
        }
        echo "\n";
    }

    private function _encrypt_4x4($matrix)
    {

    }

    private function _encrypt_3x3($matrix)
    {
        $i = 0;
        $msg_encrypt = [0, 0 , 0];
        $msg_len = strlen($this->_getMsg());
        $msg = str_split($this->_getMsg());

        while ($i < $msg_len) {
            $msg_encrypt[0] = (ord($msg[$i]) * $matrix[0]) + (ord($msg[$i + 1]) * $matrix[3]) + (ord($msg[$i + 2]) * $matrix[6]);
            $msg_encrypt[1] = (ord($msg[$i]) * $matrix[1]) + (ord($msg[$i + 1]) * $matrix[4]) + (ord($msg[$i + 2]) * $matrix[7]);
            $msg_encrypt[2] = (ord($msg[$i]) * $matrix[2]) + (ord($msg[$i + 1]) * $matrix[5]) + (ord($msg[$i + 2]) * $matrix[8]);

            printf("%d %d %d", $msg_encrypt[0], $msg_encrypt[1], $msg_encrypt[2]);

            if ($i < $msg_len - 2)
                echo " ";
            $i += 3;
	    }
       if (($i + 1) > $i && ($i + 1) < $msg_len) {
            $msg_encrypt[0] = ord($msg[$i]) * $matrix[0];
            $msg_encrypt[1] = ord($msg[$i]) * $matrix[1];
            $msg_encrypt[2] = ord($msg[$i]) * $matrix[2];

            echo " ";
            printf("%d %d %d", $msg_encrypt[0], $msg_encrypt[1], $msg_encrypt[2]);
        }

        echo "\n";
    }

    private function _encrypt_2x2($matrix)
    {
        $i = 0;
        $msg_encrypt = [0];
        $msg_len = strlen($this->_getMsg());
        $msg = str_split($this->_getMsg());

        while ($i < $msg_len) {
            $msg_encrypt[0] = (ord($msg[$i]) * $matrix[0]) + (ord($msg[$i + 1]) * $matrix[2]);
            $msg_encrypt[1] = (ord($msg[$i]) * $matrix[1]) + (ord($msg[$i + 1]) * $matrix[3]);

            printf("%d %d", $msg_encrypt[0], $msg_encrypt[1]);

            if ($i < $msg_len - 2)
                echo " ";
            $i += 3;
        }
        if (($i + 1) > $i && ($i + 1) < $msg_len) {
            $msg_encrypt[0] = ord($msg[$i]) * $matrix[0];
            $msg_encrypt[1] = ord($msg[$i]) * $matrix[1];

            echo " ";
            printf("%d %d", $msg_encrypt[0], $msg_encrypt[1]);
        }

        echo "\n";
    }

    private function _encrypt_1x1($matrix)
    {
        $msg_len = strlen($this->_getMsg());
        $msg = str_split($this->_getMsg());

        for ($i = 0; $i < $msg_len; $i++) {
            printf("%d", ord($msg[$i]) * $matrix[0]);

            if ($i < $msg_len - 1)
                printf(" ");
        }
    }

    public function displayEncryptMsg($matrix)
    {
        $size = count($matrix);

        echo "Encrypted message:\n";
        if ($size == 1)
            $this->_encrypt_1x1($matrix);
        else if ($size <= 4)
            $this->_encrypt_2x2($matrix);
        else if ($size > 4 && $size <= 9)
            $this->_encrypt_3x3($matrix);
        else if ($size > 9 && $size <= 16)
            $this->_encrypt_4x4($matrix);
    }
}
