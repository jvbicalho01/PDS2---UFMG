#include "google_password.hpp"

#include <iostream>

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
  // TODO: Implemente este metodo
  /**
   * Lembre-se que as credenciais so podem ser inseridas com as seguintes
   * condicoes:
   * Condicao 1: A senha nao pode ter a seguencia '123456'.
   * Condicao 2: A senha nao pode ter mais do que 50 caracteres (no maximo 50).
   * Condicao 3: A senha nao pode ter menos do que 6 caracteres (no minimo 6).
   * Condicao 4: A senha nao pode ter caracteres em branco ' '.
   *
   * Exemplos de senhas invalidas:
   * 123456
   * test_123456
   * 123456_test
   * test_123456_test
   * senha test
   */

  if (this->checkPassword(password)) {
    this->m_passwords.insert(
        std::pair<std::string, Usuario>(url, Usuario(login, password)));
  } else {
    return;
  }
}

void GooglePassword::remove(const std::string& url) {
  // TODO: Implemente este metodo

  m_passwords.erase(url);
}

void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& password) {
  // TODO: Implemente este metodo
  /**
   * Caso a url nao seja encontrada, o metodo update deve ser ignorado, ou seja,
   * este metodo nao pode inserir novas credenciais. Alem disso, as informacoes
   * do usuario so podem ser atualizadas se a senha antiga for igual a senha
   * atual. Nao esqueca de verificar se o novo password tambem e valido.
   */

  if (!m_passwords.count(url)) {
    return;
  } else {
    std::map<std::string, Usuario>::iterator it;

    for (it = m_passwords.begin(); it != m_passwords.end(); ++it) {
      if (it->second.getPassword() == old_password && checkPassword(password)) {
        it->second.setLogin(login);
        it->second.setPassword(password);
      }
    }
  }
}

void GooglePassword::printPasswords() {
  // TODO: Implemente este metodo
  /**
   * Exemplo de saida:
   * www.site.com: login and password
   *
   */

  std::cout << m_passwords.size() << std::endl;

  std::map<std::string, Usuario>::iterator it;

  for (it = m_passwords.begin(); it != m_passwords.end(); ++it) {
    std::cout << it->first << ": " << it->second.getLogin() << " and "
              << it->second.getPassword() << std::endl;
  }
}

bool GooglePassword::checkPassword(const std::string& password) const {
  // TODO: Implemente este metodo

  bool valida = false;
  std::size_t encontrou;

  std::string sequencia = "123456";
  int tamanho = password.length();

  if (tamanho > 50 || tamanho < 6) {
    valida = false;
    return valida;
  } else {
    valida = true;
  }

  encontrou = password.find(sequencia);

  if (encontrou != std::string::npos) {
    valida = false;
    return valida;
  } else {
    valida = true;
  }

  encontrou = password.find(' ');

  if (encontrou != std::string::npos) {
    valida = false;
    return valida;
  } else {
    valida = true;
  }

  return valida;
}
