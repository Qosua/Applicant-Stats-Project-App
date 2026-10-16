# SSH-ключ для Git

Команды вводите в терминале: на Windows — в **Git Bash** или PowerShell, на Linux/macOS — в обычном терминале.

## 1. Создайте ключ

```bash
ssh-keygen -t ed25519 -C "your_email@example.com"
```

Три раза нажмите Enter (путь и пароль можно оставить по умолчанию).

## 2. Скопируйте публичный ключ

Linux: Выведите его и скопируйте:

```bash
cat ~/.ssh/id_ed25519.pub
```

Windows: В PowerShell вместо этого:

```powershell
Get-Content $env:USERPROFILE\.ssh\id_ed25519.pub
```

## 3. Добавьте ключ в аккаунт

- **GitHub:** Settings → SSH and GPG keys → New SSH key
- **GitLab:** Preferences → SSH Keys

Вставьте ключ, дайте любое название и сохраните.

## 4. Проверьте

```bash
ssh -T git@github.com
```

Один раз ответьте `yes`. Если увидели «successfully authenticated» — всё работает.

## 5. Клонируйте по SSH

```bash
git clone git@github.com:Qosua/Applicant-Stats-Project.git
```
