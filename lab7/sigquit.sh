SIGTERM_REQUESTED=0
handle_sigterm() {
    if [ $SIGTERM_REQUESTED -eq 0 ]; then
        echo "Send SIGTERM again to terminate"
        SIGTERM_REQUESTED=1
    else
        echo "SIGTERM received, exiting now"
        exit 0
    fi
}

trap handle_sigterm SIGTERM

TIMEOUT=$(date +%s)
TIMEOUT=$(($TIMEOUT + 60))

echo "This script will exit in 60 seconds"
while [ $(date +%s) -lt $TIMEOUT ]; do
    sleep 1;
done
echo Timeout reached, exiting now