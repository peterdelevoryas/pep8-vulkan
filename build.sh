#!/usr/bin/bash

headers=$(ls orig)

for header in $headers; do
	./convert orig/$header $header
done
