#!/bin/bash

function bonErreur()
{
	echo "$1 $2 put">&2
	exit 0
}

function droma()
{
(
	pokemon=1
        chat="chatfsdfssdf"
	`bonErreur $pokemon $chat ` && echo "sortie"
)

}

droma
