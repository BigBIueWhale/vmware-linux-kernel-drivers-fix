savedcmd_vmnet.mod := printf '%s\n'   driver.o hub.o userif.o netif.o bridge.o procfs.o smac_compat.o smac.o vnetEvent.o vnetUserListener.o | awk '!x[$$0]++ { print("./"$$0) }' > vmnet.mod
