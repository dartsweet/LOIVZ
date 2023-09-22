void qs(int* chasti, int left, int right)
{
    // ������� ���� 
    int stack[100];
    int top = -1;
    int x, y;
    int j, i;

    // ��������� ��������� �������� � ����
    stack[++top] = left;
    stack[++top] = right;

    // ���� ���� �� ����
    while (top >= 0) {
        // ��������� ���� �������� �� �����
        right = stack[top--];
        left = stack[top--];

        i = left; j = right;
        x = chasti[(left + right) / 2];
        do {
            while ((chasti[i] < x) && (i < right)) i++;
            while ((x < chasti[j]) && (j > left)) j--;

            if (i <= j) {
                y = chasti[i];
                chasti[i] = chasti[j];
                chasti[j] = y;
                i++; j--;
            }
        } while (i <= j);

        // ��������� ����� ���� �������� � ����
        if (left < j) {
            stack[++top] = left;
            stack[++top] = j;
        }
        if (i < right) {
            stack[++top] = i;
            stack[++top] = right;
        }
    }
}




