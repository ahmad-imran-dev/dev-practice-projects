import "./globals.css";

export default function RootLayout({ children, parallelroute1, parallelroute2 }) {
  return (
    <html lang="en">
      <body>
        {children}
        {parallelroute1}
        {/* {parallelroute2} */}
      </body>
    </html>
  );
}
