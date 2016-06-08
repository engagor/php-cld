<?php

$functions = get_extension_funcs('cld');
print_r ($functions);

$args = array (
    "Ik ben erg hongerig",
    "I'm very hungry",
    "جائع",
    "Estou faminto",
    "j'ai très faim",
    "Tôi rất đói",
    "මම ඉතා බඩගිනි",
    "من خیلی گرسنه ام",
    "나는 매우 배고파",
    "म धेरै भोक",
    "Im 'valde ieiunus",
    "nagyon éhes vagyok",
    "I Like loa pōloli",
    "Mi tre malsatas",
    "Iu sugnu 'na fami",
    "Ako'y sobrang gutom",
    "我好餓",
    "我好饿",
    "私はとてもお腹がすいてます"
);

foreach ($args as $arg) {
    echo $arg . ": " . simple_detect($arg) . "\n";
}
