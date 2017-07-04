define reload
kill
monitor jtag_reset
load
end

target extended localhost:4242
load
b main
c
b 53
c
c
print input.data
