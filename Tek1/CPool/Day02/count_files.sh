#!/bin/bash

find . -type f -not -iwholename '*.git*' | wc -l
