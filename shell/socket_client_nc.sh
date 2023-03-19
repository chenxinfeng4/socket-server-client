#!/bin/bash
nc -q 1 localhost 20169 < <(echo "query_record")
nc -q 1 localhost 20169 < <(echo "start_record")
nc -q 1 localhost 20169 < <(echo "stop_record")
