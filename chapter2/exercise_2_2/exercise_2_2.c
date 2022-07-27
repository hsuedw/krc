
    for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)

    If we don't want to use && and ||, we can rewrite the for-loop as following while-loop.

    int i = 0, c;
    while (i < lim - 1) {
        if ((c = getchar()) != EOF) {
            break;
	}
	if (c != '\n') {
            break;
	}
	s[i] = c;
	++i;
    }
