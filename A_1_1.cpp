set ns [new Simulator]

set tracefile [open exp3.tr w]
$ns trace-all $tracefile

set namfile [open exp3.nam w]
$ns namtrace-all $namfile

for {set i 0} {$i < 7} {incr i} {
    set n($i) [$ns node]
}

for {set i 0} {$i < 6} {incr i} {
    $ns duplex-link $n($i) $n([expr $i+1]) 1Mb 10ms DropTail
}

set udp [new Agent/UDP]
$ns attach-agent $n(0) $udp

set null [new Agent/Null]
$ns attach-agent $n(6) $null

$ns connect $udp $null

set cbr [new Application/Traffic/CBR]
$cbr set packetSize_ 1000
$cbr set rate_ 1Mb
$cbr attach-agent $udp

$ns at 0.5 "$cbr start"
$ns at 25.0 "finish"

proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    close $tracefile
    close $namfile
    exec nam exp3.nam &
    exit 0
}

$ns run