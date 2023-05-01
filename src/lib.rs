mod app;
pub(crate) mod error;
mod event;
mod window;

pub use app::App;
pub use error::Error;
pub use event::Event;
pub use glfw;
pub use window::Window;
pub(crate) type Result<T> = std::result::Result<T, Error>;
