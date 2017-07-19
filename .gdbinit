define reload
kill
monitor jtag_reset
load
end
set logging on
target extended localhost:4242
load
b main
c
b 52
c
print current_state
