<?php
// Check if data was passed via CLI arguments or GET request
$data = $argv[1] ?? $_GET['data'] ?? null;

if ($data) {
    // Process your data here (e.g., save to a database or text file)
    $log = "Received at " . date('Y-m-d H:i:s') . ": " . $data . "\n";
    file_put_contents("arduino_log.txt", $log, FILE_APPEND);
    echo "Success: " . $data;
} else {
    echo "No data provided.";
}
?>