# amogdos
A work in progress meme dos clone that has an amogus theme

Amogus is a dead meme now but still I wanna make it

Bootloader: Bootboot

No Kernel Design has been made probably requires a rewrite

Bootloader is made for microkernels but Amogdos kernel isn't really a microkernel (yet) due my lazyness in writing a filesystem driver but I will surely implement it soon as possible (after i implement threading cuz threads are essential for me lol)



Anyways don't get your expectations high this won't be new freedos or winblows probably it would be collection of trash horribly programmed drivers with a kernel lacking many essential features.
Also a wise man said it's not good idea to implement graphics.h in your kernel but i didn't listen now i have sussy bakas in my house

# Current State:
There isn't even a terminal yet lmao what you are talkin' about, only super basic stuff and bunch of drivers that broken but you can change it by contributing.

## Bootable isos
Will be released in Augustus cuz os (not even an os just a crappy kernel) is so broken rn and i have other projects when I add threading and the terminal there will be a bootable iso that you can test on your vm

Features:
|Feature|Does it work?|
|-------|-------------|
|Sound| Sort of only beeps|
|Keyboard| Well it is available to access but it is unfinished but driver works so|
|Memory management| buggy af but should work to some extent|
|Threads| Nope I couldn't figure out how to make threads properly|
|Sussyness| Yes only fully working feature amogus!|
|Graphics.| Unfinished but who can't say no to bgi reimplemnentions?|

Planned Features:
|Feature|Help Needed (true or false)|Will I implement before I die|
|-------|---------------------------|-----------------------------|
|Threading| A lot| Yes|
|Networking| I need someone to write networking driver I can't pull off myself it's super complicated| no|
|File system| Not rlly I can probably implement it myself| yeah definitely|
|Mouse| No it's super simple to implement| definitely sus|

anyways a wise man said "Amogus will never die, I will keep posting amogus forever", most of people think amogus is unfunny which it is but maybe we can turn something unfunny to funny with our efforts.
It's just made to fuel up amogus again lol.

**A warning**: Never tested this on real hardware only qemu if you run this on real hardware anything could happen from your speakers playing a earrape to bricking your pc even summoning an amogus irl who knows what could happen and probably there are illegal memory accesses that could mess stuff up, only test in vms until i get brave enough and run it on cheap trash netbooks.

A sidenote: Sus sus abigus

This project has no relation to AmogOs project this project is not a linux distro it tries to

# Compiling
You can use makefile from the bootboot and just swap the kernel.c destination in the file

You need gnu cross compiler which is pain to build, I would like to include prebuild binaries somewhere but you'll think that would be a linux
also oh yeah you need loonix windows is trash anyways (it is ironic to say this on a platform owned by micro$oft corparation)
# License
Honestly I do not care what you do and I do not claim any liabilities the parts of code has mit text on it are free to use by you

i stole interrupt descriptor table from a tutorial i saw on youtube because too lazy to figure it out from the osdev.org article
tutorial doesn't specify a license but owner of tutorial forked one of people's project who had followed his tutorial so im guessing it is free to redistribute since he forked a project of a follower and most of his repos licensed mit alongside with another youtube tutorial series he has done

