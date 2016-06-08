<?php

$functions = get_extension_funcs($module);
print_r ($functions);

$args = array (
    "I Love you",
    "Ik hou van je",
    "Je t'aime",
    "Eu te amo gatinha"
);

foreach ($args as $arg) {
    echo $arg . ": " . simple_detect($arg) . "\n";
}
