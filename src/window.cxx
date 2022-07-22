#include <iostream>

#include "window.hxx"

#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <gtkmm/label.h>

Window::Window() {
  auto pmap = Gtk::make_managed<Gtk::Image>("info.xpm");
  auto label = Gtk::make_managed<Gtk::Label>("cool button");
  label->set_expand(true);

  auto hbox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 5);
  hbox->append(*pmap);
  hbox->append(*label);

  m_button.set_child(*hbox);

  set_title("Pixmap'd buttons!");

  m_button.signal_clicked().connect( sigc::mem_fun(*this,
              &Window::on_button_clicked) );

  m_button.set_margin(10);
  set_child(m_button);

  set_default_size(200, 200);
}

Window::~Window()
{
}

void Window::on_button_clicked()
{
  std::cout << "The Button was clicked." << std::endl;
}
